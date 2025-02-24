var Graph = /** @class */ (function () {
    function Graph() {
        this.list = [];
        this.size = 0;
    }
    Graph.prototype.addVertex = function () {
        this.list.push([]);
        return this.size++;
    };
    Graph.prototype.addEdge = function (u, v) {
        if (u < this.size && v < this.size) {
            this.list[u].push(v);
        }
        else {
            console.log("invalid vertexces");
        }
    };
    Graph.prototype.removeEdge = function (u, v) {
        if (u < this.size && v < this.size) {
            this.list[u] = this.list[u].filter(function (item) { return item != v; });
        }
        else {
            console.log("invalid vertexces");
        }
    };
    Graph.prototype.printGraph = function () {
        this.list.forEach(function (edges, node) {
            console.log("".concat(node, " -> ").concat(edges.join(", ")));
        });
    };
    return Graph;
}());
var graph = new Graph();
var v0 = graph.addVertex(); // 0
var v1 = graph.addVertex(); // 1
var v2 = graph.addVertex(); // 2
var v3 = graph.addVertex(); // 3
var v4 = graph.addVertex(); // 4
graph.addEdge(v0, v1);
graph.addEdge(v0, v2);
graph.addEdge(v1, v3);
graph.addEdge(v2, v4);
graph.removeEdge(v0, v1);
graph.printGraph();
