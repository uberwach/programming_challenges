// https://www.hackerrank.com/challenges/candies
object Solution {

    def main(args: Array[String]) {
        val in = scala.io.Source.stdin.getLines.map(line => line.toInt).toArray
        val N = in.head
        val ratings = in.tail

        val forwardCandy = Array.ofDim[Int](N)
        forwardCandy(0) = 1

        for (i <- 1 until N) {
            if (ratings(i) > ratings(i-1)) forwardCandy(i) = forwardCandy(i-1) + 1
            else forwardCandy(i) = 1
        }

        val backwardCandy = Array.ofDim[Int](N)
        backwardCandy(N-1) = 1
        for (i <- (N-2) to 0 by -1) {
            if (ratings(i) > ratings(i+1)) backwardCandy(i) = backwardCandy(i+1) + 1
            else backwardCandy(i) = 1
        }

        val candies = (forwardCandy zip backwardCandy) map ({case (a,b) => a max b})
        println(candies sum)
    }
}
