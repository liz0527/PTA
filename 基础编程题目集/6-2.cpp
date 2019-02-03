/*用temp存储阶乘和，fx存储总和。temp是x的循环阶乘，不需要置0*/
double f( int n, double a[], double x )
{
  double fx = 0.0;
  double temp = 1.0;
  for(int i=0; i<=n; i++) {
    if(i != 0) {
      temp *= x;
    } 
    fx += a[i] * temp; 
  }
  return fx;
}