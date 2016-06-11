// https://www.hackerrank.com/challenges/stockmax
object Solution {

  def main(args: Array[String]) {
    val T = readInt()

    for (_ <- 1 to T) {
      val N = readInt()
      val sharePrice = readLine().split(" ").map(_.toInt)
      val dp = Array.fill(N)(0) // t -> max of sharePrice[t], ..., sharePrice[N-1]

      dp(N-1) = sharePrice(N-1)
      for (t <- (N-2) to 0 by -1)
        dp(t) = Math.max(sharePrice(t), dp(t+1))

      var profit = 0L
      for (t <- 0 until (N-1)) {
        profit += Math.max(0, dp(t+1) - sharePrice(t))
      }

      println(profit)
    }
  }
}
