public class QuickUnionWithCanonical implements UnionFind {

    private int[] data;
    private int[] sz;
    private int[] maxes;
    private int components;

    public QuickUnionWithCanonical(int size) {
        data = new int[size];
        sz = new int[size];
        maxes = new int[size];
        components = size;
        for (int i = 0; i < data.length; i++) {
            data[i] = i;
            maxes[i] = i;
            sz[i] = 1;
        }
    }

    public boolean connected(int a, int b) {
        if (!isInBounds(a) || !isInBounds(b)) {
            return false;
        }

        return findRoot(data[a]) == findRoot(data[b]);
    }

    public void union(int a, int b) {
        if ((isInBounds(a) || isInBounds(b)) && !connected(a, b)) {
            if (sz[a] < sz[b]) {
                maxes[findRoot(b)] = maxes[findRoot(b)] < maxes[findRoot(a)] ? maxes[findRoot(a)] : maxes[findRoot(b)];
                data[findRoot(a)] = findRoot(b);
                sz[b] += sz[a];
            } else {
                maxes[findRoot(a)] = maxes[findRoot(a)] < maxes[findRoot(b)] ? maxes[findRoot(b)] : maxes[findRoot(a)];
                data[findRoot(b)] = findRoot(a);
                sz[a] += sz[b];
            }
            components--;
        }
    }

    public int find(int a) {
        return maxes[findRoot(a)];
    }

    private int findRoot(int a) {
        int root = data[a];
        while(root != data[root]) {
            data[root] = data[data[root]];
            root = data[root];
        }
        return root;
    }

    public boolean isFullyConnected() {
        return components == 1;
    }

    private boolean isInBounds(int a) {
        return a < data.length && a >= 0;
    }

}