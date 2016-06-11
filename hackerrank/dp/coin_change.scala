// https://www.hackerrank.com/challenges/coin-change
object Solution {

  def count(coins: Array[Int], m: Int, n: Int) : Int = {
    if (n == 0) 1
    else if (m == 0) 0
    else if (n < 0) 0
    else count(coins, m-1, n) + count(coins, m, n - coins(m-1))
  }

  def main(args: Array[String]) {
    val Array(n, m) = readLine().split(" ").map(_.toInt)
    val coins = readLine().split(" ").map(_.toInt).sorted

    val dp = Array.fill(n+1, m+1)(0L)

    for (i <- 0 to n;
         j <- 0 to m) {
      dp(i)(j) =      if (i == 0) 1
                      else if (j == 0) 0
                      else dp(i)(j-1) + (if (i - coins(j-1) >= 0) dp(i - coins(j-1))(j) else 0)
    }

    println(dp(n)(m))
  }
}
