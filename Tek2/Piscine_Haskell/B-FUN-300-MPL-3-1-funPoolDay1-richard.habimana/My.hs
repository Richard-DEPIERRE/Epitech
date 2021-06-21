mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x | x >= 0 = x
        | otherwise = x * (-1)

myMin :: Int -> Int -> Int
myMin a b | a < b = a
          | otherwise = b

myMax :: Int -> Int -> Int
myMax a b | a > b = a
          | otherwise = b

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b , c)

myFst :: (a, b) -> a
myFst (x, _) = x

mySnd :: (a, b) -> b
mySnd (_, y) = y

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "List is empty"
myHead (a:_) = a

myTail :: [a] -> [a]
myTail [] = error "List is empty"
myTail (_:a) = a

myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth [] pos = error "List is empty"
myNth list 0 = myHead list
myNth list pos | pos > myLength list = error "position is out of bound"
               | pos < 0 = error "Can't give a negative position"
               | otherwise = myNth (myTail list) (pos - 1)

myTake :: Int -> [a] -> [a]
myTake size [] = error "List is empty"
myTake 1 (a:b) = [a]
myTake size (a:b) | size >= myLength (a:b) = a:b
                  | otherwise = a:myTake (size-1) b

myDrop :: Int -> [a] -> [a]
myDrop n (a:b) | n < 0 = error "Out of bounds"
myDrop n (a:b) | n >= myLength (a:b) = []
myDrop 0 (a:b) = a:b
myDrop n (a:b) = myDrop (n - 1) b

myAppend :: [a] -> [a] -> [a]
myAppend [] list = list
myAppend (a:b) appended = a : myAppend b appended

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:b) = myAppend (myReverse b) [a]

myInit :: [a] -> [a]
myInit [] = error "List is empty"
myInit (a:b) | myLength (a:b) == 1 = []
             | otherwise = myAppend [a] (myInit b)

myLast :: [a] -> a
myLast (a:b) | myLength (a:b) == 1 = a
             | otherwise = myLast b

myZip :: [a] -> [b] -> [(a, b)]
myZip [] (a:b) = [];
myZip (a:b) [] = [];
myZip (a:b) (c:d) | myLength (a:b) == 1 = [(a, c)]
                  | myLength (c:d) == 1 = [(a, c)]
                  | otherwise = myAppend [(a, c)] (myZip b d)

myUnzip :: [(a,b)] -> ([a], [b])
myUnzip ((a, c):b) | myLength ((a, c):b) == 1 = ([a],[c])
                   | otherwise = (myAppend [a] (myFst (myUnzip b)),
                        myAppend [c] (mySnd (myUnzip b)))

myMap :: (a -> b) -> [a] -> [b]
myMap funct [] = []
myMap funct (a:b) | myLength (a:b) == 1 = [funct a]
                  | otherwise = myAppend [funct a] (myMap funct b)

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter funct (a:b) | myLength (a:b) == 1 && funct a = [a]
                     | myLength (a:b) == 1 && not (funct a) = []
                     | funct a = myAppend [a] (myFilter funct b)
                     | not (funct a) = myAppend [] (myFilter funct b)

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl funct c (a:b) | myLength (a:b) == 1 = funct c a
                      | otherwise = myFoldl funct (funct c a) b

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr funct c (a:b) | myLength (a:b) == 1 = funct a c 
                      | otherwise = myFoldr funct (funct
                      (myLast (a:b)) c) (myInit (a:b))

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition funct (a:b) | myLength (a:b) == 1 && funct a = ([a], [])
                        | myLength (a:b) == 1 && not (funct a) = ([], [a])
                        | funct a = (myAppend [a] (myFst (myPartition
                            funct b)), mySnd (myPartition funct b))
                        | not (funct a) = (myFst (myPartition funct b),
                            myAppend [a] (mySnd (myPartition funct b)))


myModPartition :: (a -> a -> Bool) -> a -> [a] -> ([a], [a])
myModPartition funct el (a:b) | myLength (a:b) == 1 && funct el a = ([a], [])
                              | myLength (a:b) == 1 && not (funct el a)
                                = ([], [a])
                              | funct el a = (myAppend [a] (myFst
                                (myModPartition funct el b)), mySnd
                                (myModPartition funct el b))
                              | not (funct el a) = (myFst (myModPartition
                                funct el b), myAppend [a] (mySnd
                                (myModPartition funct el b)))

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort funct [] = []
myQuickSort funct (a:b) | myLength (a:b) == 1 = [a]
                        | otherwise = myAppend (myQuickSort funct
                        (mySnd(myModPartition funct a b))) (myAppend
                        [a] (myQuickSort funct (myFst(myModPartition
                        funct a b))))