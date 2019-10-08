import Data.List
import Data.Char
import Text.Printf
import qualified Data.ByteString.Char8 as BS 
main = do
    str <- getLine
    putStrLn $ if analyze (reverse str) then "YES" else "NO"

analyze "" = True
analyze ('m':'a':'e':'r':'d':k) = analyze k
analyze ('r':'e':'m':'a':'e':'r':'d':k) = analyze k
analyze ('e':'s':'a':'r':'e':k) = analyze k
analyze ('r':'e':'s':'a':'r':'e':k) = analyze k
analyze _ = False
