// https://www.hackerrank.com/challenges/maxsubarray
object Solution {

    def main(args: Array[String]) {
      val t = readInt()

      for (i <- 1 to t) {
        readInt()
        val arr = readLine().split(" ").map(_.toInt)
        val (maxContSum: Int, maxSum: Int, maxElem: Long) = findMaxSumsAndElem(arr)

        if (maxElem < 0) {
          // only negative values appeared
          println(s"$maxElem $maxElem")
        } else
          println(s"$maxContSum $maxSum")


      }
    }

    def findMaxSumsAndElem(arr: Array[Int]): (Int, Int, Long) = {
      val (_, maxContSum, maxSum, maxElem) = arr.foldLeft((0, 0, 0, Long.MinValue)) { case ((currentSum, maxContSum, maxSum, maxElem), value) => {
        val possibleNextSum = currentSum + value
        val newCurrentSum = Math.max(0, possibleNextSum)
        val newMaxContSum = Math.max(maxContSum, possibleNextSum)
        val newMaxSum = maxSum + Math.max(0, value)
        val newMaxElem = Math.max(maxElem, value)
        (newCurrentSum, newMaxContSum, newMaxSum, newMaxElem)
        }
      }
      (maxContSum, maxSum, maxElem)
    }
}
