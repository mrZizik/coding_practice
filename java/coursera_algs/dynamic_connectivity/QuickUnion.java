public class QuickUnion implements UnionFind {

    private int[] data;
    private int components;

    public QuickUnion(int size) {
        data = new int[size];
        components = size;
        for (int i = 0; i < data.length; i++) {
            data[i] = i;
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
            data[findRoot(a)] = findRoot(b);
            components--;
        }
    }

    private int findRoot(int a) {
        int root = data[a];
        while(root != data[root]) {
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