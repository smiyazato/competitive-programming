--ghc
import Control.Applicative
import Text.Printf

main = do
  -- "L M N" ---> [L,M,N]
  n <- fmap (read :: String -> Int) . words <$> getLine
  -- 複数行バージョン
  --ns <- fmap (fmap (read :: String -> Int) . words) . lines <$> getContents
  mapM_ print n