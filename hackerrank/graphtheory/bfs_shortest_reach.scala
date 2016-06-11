// https://www.hackerrank.com/challenges/bfsshortreach

object Solution {

    def main(args: Array[String]) {
        val T = readInt()

        for (_ <- 1 to T) {
            val Array(n, m) = readLine().split(" ").map(_.toInt)

            var edges = Map[Int, List[Int]]().withDefaultValue(Nil)
            for (_ <- 1 to m) {
                val Array(n1, n2) = readLine().split(" ").map(_.toInt - 1)
                edges += n1 -> (n2 :: edges(n1))
                edges += n2 -> (n1 :: edges(n2))
            }

            val s = readInt() - 1
            val dists = Array.fill(n)(-1)
            dists(s) = 0

            var queue = scala.collection.mutable.Queue[Int](s)

            while (!queue.isEmpty) {
                val node = queue.dequeue()

                for (nextNode <- edges(node);
                     if dists(nextNode) == -1) {
                    queue.enqueue(nextNode)
                    dists(nextNode) = dists(node) + 1
                }

            }

            val adjDists = dists.map(x => if (x != -1) x * 6 else -1)

            var result = ""
            for (i <- 0 until n;
                 if i != s)
                    result += adjDists(i) + " "
            println(result)
        }
    }
}
