--ghc
import Data.List
import Data.Char
import Text.Printf
import qualified Data.ByteString.Char8 as BS 
main = do
    [n, y] <- unfoldr (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine
    let ex = last $ ["-1", "-1", "-1"] : [map show [u, v, n - u - v] | u <- [0..n], v <- [0..n-u], u * 10000 + v * 5000 + (n - u - v) * 1000 == y] 
    putStrLn $ ex!!0 ++ " " ++ ex!!1 ++ " " ++ ex!!2
