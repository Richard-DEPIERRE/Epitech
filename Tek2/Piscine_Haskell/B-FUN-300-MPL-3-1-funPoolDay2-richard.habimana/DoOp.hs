import System.Environment
import System.Exit

myElem :: Eq a => a -> [a] -> Bool
myElem a [] = False
myElem c (a:b) | length (a:b) == 1 = a == c
               | c == a = True
               | otherwise = myElem c b

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (x `div` y)

myHead :: [a] -> a
myHead [] = error "List is empty"
myHead (a:_) = a

safeNth :: [a] -> Int -> Maybe a
safeNth [] pos = Nothing
safeNth (a:b) 0 = Just a
safeNth list pos | pos > length list = Nothing 
                 | pos < 0 = Nothing 
                 | otherwise = safeNth (tail list) (pos - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc (Just x) = Just (x+1)
safeSucc _ = Nothing

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup nb [] = Nothing
myLookup nb ((a,b):c) | nb == a = Just b
                      | otherwise = myLookup nb c

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo funct (Just a) (Just b) = Just (funct a b)
maybeDo funct _ (Just b) = Nothing
maybeDo funct (Just a) _ = Nothing

checkInt :: [Char] -> Bool
checkInt [] = False
checkInt ('-':b) = checkInt b
checkInt (a:b) | length (a:b) == 1 && a >= '0' && a <= '9' = True
               | length (a:b) == 1 && (a < '0' || a > '9') = False
               | a >= '0' && a <= '9' = checkInt b
               | (a < '0' || a > '9') = False

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt (a:b) | not (checkInt (a:b)) = Nothing
              | otherwise = Just (read (a:b) :: Int)

getLineLength :: IO Int
getLineLength = length <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength str = putStr str >>
                        putStr "\n" >>
                        return (length str)

printMiddle :: Int -> Char -> IO ()
printMiddle 0 m = putStr ""
printMiddle a m = putStr [m] >>
                  printMiddle (a - 1) m

printside :: Int -> Char -> Char -> IO ()
printside a s m = putStr [s] >>
                  printMiddle (a - 2) m >>
                  putStr [s] >>
                  putStr "\n"

printmiddle :: Int -> Int -> IO ()
printmiddle a 0 = putStr ""
printmiddle a b = printside (a * 2) '|' ' ' >>
                  printmiddle a (b - 1)

printBox :: Int -> IO ()
printBox a | a <= 0 = putStr ""
printBox 1 = putStr "++\n"
printBox a = printside (a * 2) '+' '-' >>
             printmiddle a (a - 2) >>
             printside (a * 2) '+' '-'

getLines :: Int -> String -> IO String
getLines 0 lines = return lines
getLines n lines = do
    line <- getLine
    getLines (n-1) (lines ++ line)

concatLines :: Int -> IO String
concatLines a = getLines a ""

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine

checkErrors :: [a] -> IO ()
checkErrors (a:b) | length (a:b) == 3 = putStr ""
                  | otherwise = exitWith (ExitFailure 84)

-- divCalc :: [Char] -> [Char] -> IO ()
-- divCalc x z = do
--     case safeDiv (read x :: Int) (read z :: Int) of
--         Just a -> print a
--         Nothing -> print 3

-- calculate :: [[Char]] -> IO ()
-- calculate (x:y:z:b) | y == "+" = print ((read x :: Int) + (read z :: Int))
--                     | y == "-" = print ((read x :: Int) - (read z :: Int))
--                     | y == "*" = print ((read x :: Int) * (read z :: Int))
--                     | y == "/" = divCalc x y
--                     | otherwise = exitWith (ExitFailure 84)

main :: IO ()
main = do
    args <- getArgs
    checkErrors args
--     calculate args
