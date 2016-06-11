// https://www.hackerrank.com/challenges/string-reduction
object Solution {

    def main(args: Array[String]) {
        val T = readInt()
        val chars = List('a', 'b', 'c')
        val enc = chars.zipWithIndex.toMap // maps chars to numbers
        val permutations = chars.permutations.toList.map(chs => chs map enc.apply)

        for (t <- 1 to T) {
            // println(s"Starting test case $t")
            val line = readLine()
            val n = line.size
            val dp = Array.fill[Int](n, n, enc.size)(1001)
            // i, j, c = shortest seq c reducible from s[i] to s[j]
            // 0 <= i <= j <= n, c in {'a', 'b', 'c'}
            // result is min_{c}(dp(0, n, c))

            for (i <- 0 until n;
                 ch = line(i))
                    dp(i)(i)(enc(ch)) = 1


            for (delta <- 1 to n-1;
                 i <- 0 until n) {
                    if (i + delta < n) {
                        val j = i + delta
                        for (List(c1, c2, c3) <- permutations;
                             k <- i until j) {
                            dp(i)(j)(c1) = Math.min(dp(i)(j)(c1), dp(i)(k)(c1) + dp(k+1)(j)(c1)) // simple addition
                            val s = dp(i)(k)(c1)
                            val t = dp(k+1)(j)(c2)
                            if (s != 1001 && t != 1001) {
                                  if (s % 2== 0) dp(i)(j)(c2) = Math.min(dp(i)(j)(c2), t)
                                  else if (t % 2 == 0) dp(i)(j)(c1) = Math.min(dp(i)(j)(c1), s)
                                  else dp(i)(j)(c3) = 1
                            }
                        }

                    }
                    // case 2: can extend to the left
                    if (i - delta >= 0) {
                        val j = i - delta
                        for (List(c1, c2, c3) <- permutations;
                             k <- j until i) {
                            dp(j)(i)(c1) = Math.min(dp(j)(i)(c1), dp(j)(k)(c1) + dp(k+1)(i)(c1)) // simple addition
                            val t = dp(j)(k)(c2)
                            val s = dp(k+1)(j)(c1)
                            if (s != 1001 && t != 1001) {
                                if (s % 2 == 0) dp(i)(j)(c2) = Math.min(dp(i)(j)(c2), t)
                                else if (t % 2 == 0) dp(i)(j)(c1) = Math.min(dp(i)(j)(c1), s)
                                else dp(i)(j)(c3) = 1
                            }
                        }
                    }
            }
            /*
            for (i <- 0 until n;
                 j <- 0 until n;
                 c <- chars) {
                println(i + " to " + j + ": " + c + " = " + (dp(i)(j)(enc(c))))
            }*/

            val results = for (c <- chars)
                          yield (dp(0)(n-1)(enc(c)))

            println(results min)
        }
    }
}
