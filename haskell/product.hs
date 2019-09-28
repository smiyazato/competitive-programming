--ghc
module Main where
import System.Environment    
import Control.Applicative
import Text.Printf
    
main = do
  [m, n] <- map read . words <$> getLine
  if (m * n `mod` 2 == 0) then putStrLn "Even" else putStrLn "Odd"
