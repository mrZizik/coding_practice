class SocialNetworkConnectivity {
    public static void main(String[] args) {
        int N = 100;
        UnionFind uf = new QuickUnionFind(N);
        long time = 0;

        while (!uf.isFullyConnected()) {
            // Call uf.connected(int user1, int user2) for each time entry and save entry to time variable
        }
        
        System.out.println(time); // When all users are connected uf.isFullyConnected() will return true and we can output time
    }
}