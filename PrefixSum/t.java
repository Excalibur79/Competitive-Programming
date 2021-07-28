package PrefixSum;

import java.io.*;
import java.util.*;
class SHIVIGOD
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        int i,j,N,A,B;
        double avg,tmp;
        
        //avg = stores maximum average
        //tmp = stores sum of elements of current subarray

        int T=Integer.parseInt(br.readLine().trim());
        StringBuilder sb=new StringBuilder();

        while(T-->0)
        {
            avg=0.0;

            String s[]=br.readLine().trim().split(" ");
            N=Integer.parseInt(s[0]);
            B=Integer.parseInt(s[1]);
            A=Integer.parseInt(s[2]);

            s=br.readLine().trim().split(" ");
            double a[]=new double[N+1];

            //maintaining the prefix sums array
            for(i=0;i<N;i++)
                a[i+1]=a[i]+Long.parseLong(s[i]);

            //subarray of size i
            for(i=A;i<=B;i++)
            {
                tmp=a[i];

                avg=Math.max(avg,tmp/i);

                //subarray starting at j
                for(j=i+1;j<=N;j++)
                {
                    tmp=a[j]-a[j-i];

                    avg=Math.max(avg,tmp/i);
                }
            }

            sb.append(avg).append("\n");
        }

        System.out.println(sb);
    }
}