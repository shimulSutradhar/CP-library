<snippet>
    <content><![CDATA[
ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a % b);
}

]]></content>
  <tabTrigger>mygcd</tabTrigger>
  <source>source.cpp</source>
</snippet>
