#include <iostream>
using namespace std;

void quicksort(int *A, int l, int r) {
  if(l < r) {
    int p = l, k = l+1;
    while(k <= r) {
      if(A[k] < A[l]) {
	swap(A[p+1],A[k]);
	p = p+1;
      }
      k = k+1;
    }
    swap(A[l],A[p]);
    quicksort(A, l, p-1);
    quicksort(A, p+1, r);
  }
}

int main() {
  int N, L, R;
  cout << "Print N: ";
  cin >> N;
  int A[N+1];
  for(int i=1; i<=N; i++) cin >> A[i];
  cout << "Print L and R: ";
  cin >> L >> R;

  quicksort(A, L, R);

  for(int i=1; i<=N; i++) cout << A[i] << " ";
  cout << endl;
  return 0;
  //aaaaaaaaaaa
}