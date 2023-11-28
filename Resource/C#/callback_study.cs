class A()
{
    void A함수1(B b)
    {
        b.B함수1(this);
    }

    void A함수2()
    {
        Console.Write("함수2");
    }
}

class B()
{
    void B함수1(A a)
    {
        a.A함수2();
    }
}