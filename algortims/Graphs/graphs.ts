class Graph {
  list: number[][];
  size: number;

  constructor() {
    this.list = [];
    this.size = 0;
  }

  addVertex(): number {
    this.list.push([]);
    return this.size++;
  }

  addEdge(u: number, v: number): void {
    if (u < this.size && v < this.size) {
      this.list[u].push(v);
    } else {
      console.log("invalid vertexces");
    }
  }

  removeEdge(u: number, v: number) {
    if (u < this.size && v < this.size) {
      this.list[u] = this.list[u].filter((item) => item != v);
    } else {
      console.log("invalid vertexces");
    }
  }

  printGraph(): void {
    this.list.forEach((edges, node) => {
      console.log(`${node} -> ${edges.join(", ")}`);
    });
  }
}

class GraphWithMatrix {
  list: number[][];
  size: number;

  constructor() {
    this.list = [];
    this.size = 0;
  }

  add
}

const graph = new Graph();

const v0 = graph.addVertex(); // 0
const v1 = graph.addVertex(); // 1
const v2 = graph.addVertex(); // 2
const v3 = graph.addVertex(); // 3
const v4 = graph.addVertex(); // 4

graph.addEdge(v0, v1);
graph.addEdge(v0, v2);
graph.addEdge(v1, v3);
graph.addEdge(v2, v4);
graph.removeEdge(v0, v1);

graph.printGraph();
