--ghc
import Data.List
import Control.Monad
import Text.Printf
main = do
    n <- readLn
    list <- replicateM n getLine
    print $ length $ nub $ map (read :: String -> Int) list
