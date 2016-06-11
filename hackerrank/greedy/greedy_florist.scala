// https://www.hackerrank.com/challenges/greedy-florist

object Solution {

  def main(args: Array[String]) {
    val Array(n, k) = readLine().split(" ").map(_.toInt)
    val cs = readLine().split(" ").map(_.toInt).sorted.reverse
    var counter = 0L
    var xs = Array.fill(k)(0)

    for (i <- 0 until n) {
      val nextBuyer = (0 until k).minBy(j => xs(j))
      counter += (xs(nextBuyer) + 1) * cs(i)
      xs(nextBuyer) += 1
    }

    println(counter)
  }
}
