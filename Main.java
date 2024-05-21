public class Main {
    public static void main(String[] args) {
        // String s1 = "hello";
        // String s2 = new String("hello");
        // String s3 = s2.intern();
        // System.out.println(s1 == s2);
        // System.out.println(s2 == s3);
        // System.out.println(s1 == s3);

        MyClass mc = new MyClass(20);
        System.out.println(mc.modifyX(20));
        System.out.println(mc.x);
    }
}

class MyClass {
    int x;

    public MyClass(int x) {
        this.x = x;
    }

    public MyClass modifyX(int newX) {
        this.x = newX;
        return this;
    }
}
