public class QuickFind implements UnionFind {

    private int[] data;
    private int components;

    public QuickFind(int size) {
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

        return data[a] == data[b];
    }

    public void union(int a, int b) {
        if ((isInBounds(a) || isInBounds(b)) && !connected(a, b)) {
            for (int i = 0; i < data.length; i++) {
                if (data[i] == data[a]) {
                    data[i] = data[b];
                }
            }
            components--;
        }
    }

    public boolean isFullyConnected() {
        return components == 1;
    }

    private boolean isInBounds(int a) {
        return a < data.length && a >= 0;
    }

}