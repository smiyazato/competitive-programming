import Data.List
import Data.Char
import Text.Printf
import Control.Monad
main = do
    n <- readLn
    input <- replicateM n $ map (read :: String -> Int) . words <$> getLine
    putStrLn $ if analyze input then "Yes" else "No"

analyze [] = True
analyze (x:xs)= if (x!!1 + x!!2 <= x!!0) && (sum x `mod` 2 == 0) then analyze xs else False
