delegate void Delegate1();

class A()
{
    void A함수1(B b)
    {
        Delegate1 delegateA = A함수2;
        b.B함수1(delegateA);
    }

    void A함수2()
    {
        Console.Write("함수2");
    }
}

class B()
{
    void B함수1(Delegate1 delA)
    {
        delA();
    }
}