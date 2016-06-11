// https://www.hackerrank.com/challenges/dijkstrashortreach

import scala.collection.mutable.PriorityQueue

/**
 * Created by gerrit on 03.09.15.
 */
object Solution {

  // links: nodeindex -> cost
  case class Node(index: Int, var links: Map[Int, Int]) {
    lazy val neighbours = links.keys
  }

  /**
   * Dijkstra algorithm on graphs with V = [n].
   *
   * @param start
   * @param nodes
   * @return dp array with dp(i) = Cost from node start to node i+1
   */
  def dijkstra(startIndex: Int, nodes: Map[Int, Node]) : Array[Long] = {
    type NextStep = (Node, Int) // Node and cost
    implicit val nextStepOrder = Ordering.fromLessThan[NextStep]( (s1: NextStep, s2: NextStep) => s1._2 < s2._2).reverse

    var visited = Set[Int]()
    val dp = Array.fill(nodes.size)(-1L)
    dp(startIndex-1) = 0
    val queue = PriorityQueue[NextStep]((nodes(startIndex), 0))

    while (!queue.isEmpty) {
      val (currNode, currCost) = queue.dequeue()

      for (nextNodeIdx <- currNode.neighbours;
           if !visited.contains(nextNodeIdx)) {
        val nextCost = currCost + currNode.links(nextNodeIdx) // cost if going via currNode to nextNode
        if (nextCost < dp(nextNodeIdx-1) || dp(nextNodeIdx-1) == -1) {
          dp(nextNodeIdx-1) = nextCost
          queue.enqueue((nodes(nextNodeIdx), nextCost))
        }
      }

      visited += currNode.index
    }
    dp
  }
  def main(args: Array[String]) {
    val t = readInt()
    for (_ <- 1 to t) {
      val Array(n, m) = readLine().split(" ").map(_.toInt)
      var nodes = Map[Int, Node]()
      for (i <- 1 to n)
        nodes += i-> Node(i, Map[Int, Int]())

      for (i <- 1 to m) {
        val Array(x, y, cost) = readLine().split(" ").map(_.toInt)
        val nodex = nodes(x)
        val nodey = nodes(y)

        nodex.links += y -> (if (nodex.links.contains(y)) Math.min(cost, nodex.links(y)) else cost)
        nodey.links += x -> (if (nodey.links.contains(x)) Math.min(cost, nodey.links(x)) else cost)
      }

      val s = readInt()
      val dp = dijkstra(s, nodes)

      for (i <- 1 to n;
           if i != s)
            print(dp(i-1) + " ")

      println("")
    }
  }
}
