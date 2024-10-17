#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

// hàm kiểm tra số nguyên tố

bool checkPrime(int n){
    if(n<2) return false;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            return false;
        } 
        }
        return true;
    }

    //Tạo mảng chứa số nửa nguyên tố blum nhỏ hơn N

    vector<int> array_blumNumbers(int N){
        vector<int> primes;
        vector<int> blumNumbers;

        //Tìm các số nguyên tố có dạng 4k+3
        for(int i=0;i<N;i++){
            if( checkPrime(i) && i%4==3){
             primes.push_back(i);   
    
            }

            }

    //Taọ số nguyên tố blum từ các số nguyên tố trên

    for(int i=0;i<primes.size();i++){
        for(int j=i;j<primes.size();j++){
            int blum=primes[i]*primes[j];
            if(blum<N){
            //Kiểm tra xem blum đã tồn tại trong blumNumbers hay chưa
            bool exist=false;
            for(int k=0;k<blumNumbers.size();k++){
                if(blumNumbers[k]==blum) {
                exist=true;
                break;
                }
            }
            if(!exist){
                blumNumbers.push_back(blum);
            }   
            }
        }
    }

    //Săp xếp blumNumbers

    for(int i=0; i<blumNumbers.size()-1; i++){
        for(int j=i+1; j<blumNumbers.size(); j++){
            if(blumNumbers[i]>blumNumbers[j]){
                swap(blumNumbers[i], blumNumbers[j]);
    
        }
    }
    }
    return blumNumbers;
    }
    // 1.Tìm các cặp số blum có tổng cũng là 1 số blum nhỏ hơn N

/*Do số blum= tích của 2 số nguyên tố dạng 4k+3 nên blum là số lẻ
        => Tổng 2 số blum bất kì là 1 số chẵn
        => Không thê tồn tại 1 cặp số blum có tổng cũng là 1 số blum(do mâu thuân) */

    vector<pair<int,int>> findBlum( vector<int> &blumNumbers, int N){
        vector<pair<int,int>> pairs;
        for(int i=0;i<blumNumbers.size();i++){
            for(int j=i+1;j<blumNumbers.size();j++){
                int sum=blumNumbers[i]+blumNumbers[j];
                //Tìm kiếm xem sum có nằm trong blumNumbẻrs không
                bool exist=false;
                for(int k=0;k<blumNumbers.size();k++){
                    if(blumNumbers[k]==sum){
                        exist=true;
                        break;
                    }
                }
                if(sum<N && exist){
                    pairs.push_back({blumNumbers[i], blumNumbers[j]});
        } 

    }
        }
        
     if(pairs.empty()){
        cout<<"Khong co cac cap so blum co tong cung la so blum nho hon "<<N<<endl;
     }   else {
        cout<<"Cac cap so blum co tong cung la so blum nho hon "<<N<<":";
        for(int i=0;i<pairs.size();i++){
            cout<<"("<<pairs[i].first<<","<<pairs[i].second<<") ";
        }
        cout<<endl;
     }
     return pairs;
     
    }


    //2. Kiểm tra xem 1 số blum M có tồn tại hay khôg

    bool checkBlum(int M, const vector<int> &blumNumbers){
        for(int i=0; i<blumNumbers.size();i++){
            if(blumNumbers[i]==M){
                return true;
            }
    
            }
            return false;
        }

        int main(){
            int N,M;
            cin>>N;

            //Tạo mảng số nửa nguyên tố blum nhỏ hơn N
            vector<int> blumNumbers=array_blumNumbers(N);

            //In ra các số blum nhỏ hơn N
            cout<<"Cac so blum nho hon "<<N<<":";
            for(int i=0;i<blumNumbers.size();i++){
                
                cout<<blumNumbers[i]<<" ";
            }
            cout<<endl;

            //In ra các căp có tổng cũng là số blum nhỏ hơn N

            
            vector<pair<int,int>> blumPairs=findBlum(blumNumbers,N);
           

            // Kiểm tra số blum M

            cin>>M;
            if(checkBlum(M,blumNumbers)){
                cout<<"M co ton tai trong day so blum ";
            }else {
                cout<<"M khong ton tai trong day so blum ";
            }
            return 0;
            
        }
    
