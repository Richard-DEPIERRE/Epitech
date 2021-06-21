import System.Environment
import System.Exit
import Data.List ()
import Data.Char

checkArray :: [[Char]] -> Bool
checkArray [] = True
checkArray (a:b) | all isDigit a = checkArray b  
                 | otherwise = False

checkErrors :: [[Char]] -> IO ()
checkErrors [] = exitWith (ExitFailure 84)
checkErrors (a:b) | checkArray (a:b) = putStr ""
                  | otherwise = putStr "KO: Please put only numbers\n" >>
                    exitWith (ExitFailure 84)

getArray :: [String] -> [Int]
getArray [x] = [read x :: Int]
getArray (x:xs) = (read x :: Int): getArray xs

getCommands :: String -> [String]
getCommands = words

swapAction :: [Int] -> [Int]
swapAction [a] = [a]
swapAction (a:b:c) | length (a:b:c) == 1 = a:b:c
                   | otherwise = b:a:c

putAction :: ([Int],[Int]) -> ([Int],[Int])
putAction (a:b, []) = (a:b, [])
putAction ([], c:d) = ([c], d)
putAction (a:b, c:d) = (c:a:b, d)

putAction2 :: ([Int],[Int]) -> ([Int],[Int])
putAction2 ([], []) = ([], [])
putAction2 (a:b, []) = (b, [a])
putAction2 ([], c:d) = ([], c:d)
putAction2 (a:b, c:d) = (b, a:c:d)

printMe :: [Int] -> IO ()
printMe = print

rrotateAction :: [Int] -> [Int]
rrotateAction (a:b) = init (last (a:b):a:b)

rotateAction :: [Int] -> [Int]
rotateAction a = a

rbAction :: [Int] -> [Int]
rbAction (a:b) = b ++ [a]

doAction :: ([Int],[Int]) -> String -> ([Int],[Int])
doAction (a:b,[]) "sa" = (swapAction (a:b), [])
doAction ([],c:d) "sa" = ([], c:d)
doAction (a:b,c:d) "sa" = (swapAction (a:b), c:d)

doAction (a:b,[]) "sb" = (a:b,[])
doAction ([],c:d) "sb" = ([], swapAction (c:d))
doAction (a:b,c:d) "sb" = (a:b, swapAction (c:d))

doAction (a:b,[]) "sc" = (swapAction (a:b), [])
doAction ([],c:d) "sc" = ([], swapAction (c:d))
doAction (a:b,c:d) "sc" = (swapAction (a:b), swapAction (c:d))

doAction (a:b,[]) "pa" = (a:b,[])
doAction ([],c:d) "pa" = putAction ([],c:d)
doAction (a:b,c:d) "pa" = putAction (a:b,c:d)

doAction (a:b,[]) "pb" = putAction2 (a:b,[])
doAction ([],c:d) "pb" = putAction2 ([],c:d)
doAction (a:b,c:d) "pb" = putAction2 (a:b,c:d)

doAction (a:b,[]) "ra" = (rbAction (a:b), [])
doAction ([],c:d) "ra" = ([], c:d)
doAction (a:b,c:d) "ra" = (rbAction (a:b), c:d)

doAction (a:b,[]) "rb" = (a:b, [])
doAction ([],c:d) "rb" = ([], rbAction (c:d))
doAction (a:b,c:d) "rb" = (a:b, rbAction (c:d))

doAction (a:b,[]) "rr" = (rbAction (a:b), [])
doAction ([],c:d) "rr" = ([], rbAction (c:d))
doAction (a:b,c:d) "rr" = (rbAction (a:b), rbAction (c:d))

doAction (a:b,[]) "rra" = (rrotateAction (a:b), [])
doAction ([],c:d) "rra" = ([], c:d)
doAction (a:b,c:d) "rra" = (rrotateAction (a:b), c:d)

doAction (a:b,[]) "rrb" = (a:b,[])
doAction ([],c:d) "rrb" = ([], rrotateAction (c:d))
doAction (a:b,c:d) "rrb" = (a:b, rrotateAction (c:d))

doAction (a:b,[]) "rrr" = (rrotateAction (a:b), [])
doAction ([],c:d) "rrr" = ([], rrotateAction (c:d))
doAction (a:b,c:d) "rrr" = (rrotateAction (a:b), rrotateAction (c:d))

checkString :: [Int] -> Bool
checkString [] = True
checkString [a] = True
checkString (a:b:c) | a > b = False
                    | otherwise = checkString (b:c)

isSorted :: ([Int],[Int]) -> [String] -> Bool
isSorted ([],[]) [] = False
isSorted ([a],[]) [] = True
isSorted ([],[b]) [] = False
isSorted (a:b,[]) [] = checkString (a:b)
isSorted (a:b,c:d) [] = False
isSorted (a:b,[]) (x:xs) = isSorted (doAction (a:b,[]) x) xs
isSorted ([],c:d) (x:xs) = isSorted (doAction ([],c:d) x) xs
isSorted (a:b,c:d) (x:xs) = isSorted (doAction (a:b,c:d) x) xs

checkPushSwap :: [Int] -> [String] -> IO ()
checkPushSwap (a:b) [] | isSorted (a:b,[]) [] = putStr "OK\n"
                       | otherwise = putStr "KO: String is not Sorted\n" >> 
                         exitWith (ExitFailure 84)
checkPushSwap (a:b) (c:d) | isSorted (a:b,[]) (c:d) = putStr "OK\n"
                          | otherwise = putStr "KO: String is not Sorted\n" >>
                              exitWith (ExitFailure 84)

goodCommand :: String -> Bool
goodCommand "sa" = True
goodCommand "sb" = True
goodCommand "sc" = True
goodCommand "pa" = True
goodCommand "pb" = True
goodCommand "ra" = True
goodCommand "rb" = True
goodCommand "rr" = True
goodCommand "rra" = True
goodCommand "rrb" = True
goodCommand "rrr" = True
goodCommand a = False

checkErrorsCommands :: [String] -> IO ()
checkErrorsCommands [] = putStr ""
checkErrorsCommands [a] | not (goodCommand a) =
                              putStr "KO: Please input correct commands\n" >>
                              exitWith (ExitFailure 84)
checkErrorsCommands (a:b) | not (goodCommand a) =
                                putStr "KO: Please input correct commands\n" >>
                                exitWith (ExitFailure 84)
                          | otherwise = checkErrorsCommands b

main :: IO ()
main = do
    s <- getLine
    args <- getArgs
    checkErrors args
    checkErrorsCommands (getCommands s)
    checkPushSwap (getArray args) (getCommands s)