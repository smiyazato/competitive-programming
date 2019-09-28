--ghc
module Main where
    import System.Environment    
    import Control.Applicative
    import Text.Printf
        
    main = do
      [l, m, n] <- map read . words <$> getLine
      print $ length $ filter (== 1) [l, m, n]
