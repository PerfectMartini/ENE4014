fun map (f, xs) =
  case xs of
    [] => []
  | x :: xs' => (f x) :: (map (f, xs'))