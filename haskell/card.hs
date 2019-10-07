--ghc
import Data.List
import Text.Printf
main = do
    getLine
    cards <- map (read :: String -> Int) . words <$> getLine
    print $ sum $ zipWith (*) (cycle [1, -1]) $ reverse $ sort cards
