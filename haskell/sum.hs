--ghc
module Main where
import Data.Char
import System.Environment    
import Control.Applicative
import Text.Printf
digits :: Int -> [Int]
digits = map digitToInt . show
main = do
    [l, m, n] <- map read . words <$> getLine
    print $ sum [u | u <- [1..l], m <= (sum $ digits u) && (sum $ digits u) <= n]
