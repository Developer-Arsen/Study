// function add(a, b) {
//   return a + b;
// }

// function run() {
//   for (let i = 500_000; i < 1_000_000; i++) {
//     add(i, i + 1); // Optimized 🚀
//   }

//   add("3", "4"); // ❌ Deoptimization! Different argument types
// }

// let arsen = () => {};

// arsen();
// run();

const Tarjan = (edges) => {
  const len = edges.len;
  const graph = new Array(len).fill(null).map(() => []);
  const disc = new Array(len).fill(0);
  const ll = new Array(len).fill(-1);
  const stack = new Array(len).fill(0);
  const res = [];
  const onStack = [];

  for (const [u, v] of edges) {
    graph[u].push(v);
  }
  let id = 0;
  const dfs = (u) => {
    if (disc[u]) return;
    disc[u] = ll[u] = id++;
    onStack[u] = 1;
    stack.push(u);

    for (const v of graph[u]) {
      if (!disc[v]) {
        dfs(v);
        ll[u] = Math.min(ll[u], ll[v]);
      }
      else if (onStack[v]) {
        ll[u] = Math.min(ll[u], ll[v]);
      }
    }
    if (ll[u] == disc[u]) {
      let tmp = [];
      while (stack.length) {
        const num = stack.pop();
        tmp.push(num);
        if (num == u) break;
      }
      res.push(tmp);
    }
  };

  for (let i = 0; i < len; ++i) {
    if (!disc[i]) {
      dfs(i);
    }
  }
  return res;
};
