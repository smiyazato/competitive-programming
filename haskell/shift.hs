--ghc
module Main where
import System.Environment    
import Control.Applicative
import Text.Printf           
f x = if x `mod` 2 == 0 then 1 + f (x `div` 2) else 0
main = do
    x <- readLn :: IO Int
    y <- map read . words <$> getLine
    print $ minimum $ map f y
