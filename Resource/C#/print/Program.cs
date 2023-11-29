using System;
class Program
{
    static void Main()
    {
        int nN=default;
        nN=23323;
        float nF=default;
        nF=3.49F;
        string strA="dfadd";
        long lngB=1000000000000000l;
        double dbC=0.55555555D;
        long lnA=nN;
        double dbF=default;
        dbF=nF;
        int nNew=(int)nF;
        string strNew=nN.ToString();
        string strNew2="123";
        int nNew2=int.Parse(strNew2);
        Console.WriteLine(nNew);
        // Console.WriteLine(strNew);
        // Console.WriteLine(nNew);
        // Console.WriteLine(nF);
    }
}