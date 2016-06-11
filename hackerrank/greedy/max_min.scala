// https://www.hackerrank.com/challenges/angry-children

object Solution {

  def main(args: Array[String]) {
    val input = scala.io.Source.stdin.getLines drop 1

    val k = input.next.toInt
    val numbers = input.map(_.toInt).toVector.sorted

    val possibleUnfairness = for (i <- 0 to (numbers.length - k)) yield (numbers(i + k - 1) - numbers(i))
    println(possibleUnfairness min)
  }
}
