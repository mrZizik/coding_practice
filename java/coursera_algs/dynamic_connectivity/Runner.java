class Runner {
    public static void main(String[] args) {
        QuickUnionWithCanonical uf = new QuickUnionWithCanonical(5);
        
        uf.union(0, 1);
        uf.union(1, 2);
        System.out.println(uf.find(1));
        System.out.println(uf.find(0));
        System.out.println(uf.find(3));
        uf.union(3, 4);
        System.out.println(uf.find(3));
        System.out.println(uf.find(4));
        uf.union(0, 4);
        System.out.println(uf.find(1));
        System.out.println(uf.find(0));
    }
}