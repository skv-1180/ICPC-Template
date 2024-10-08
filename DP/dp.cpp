{
	"Longest Common Subsequence": {
		"prefix": "lcs",
		"scope": "cpp",
		"body": [
		  "//--O(N*M)---S(Min(N,M)--//",
		  "template<class T> int lcs(vector<T>&first,vector<T>&second){",
		  "    vector<int>current(second.size()+1,0);    ",
		  "    vector<int>next(second.size()+1,0);",
		  "    for(int i=first.size()-1;i>=0;i--){",
		  "        for(int j=second.size()-1;j>=0;j--){",
		  "            int length=0;",
		  "            if(first[i]==second[j])length=1+next[j+1];",
		  "            else length=max(next[j],current[j+1]);",
		  "            current[j]=length;",
		  "        }",
		  "        next=current;",
		  "    }",
		  "    return next[0];",
		  "}"
		],
		
		"description": "Longest Common Subsequence"
	  },
	  "Lowest Increasing subsequence": {
		"prefix": "lis",
		"scope": "cpp",
		"body": [
		  "//T.C.:O(Nlog(N)) M.C.:O(N)",
		  "template<class T>  int lis(vector<T>&v){",
		  "    vector<int>dp;",
		  "    for(int i=0;i<v.size();i++){",
		  "        auto it=lower_bound(begin(dp),end(dp),v[i]);",
		  "        if(it==dp.end())dp.push_back(v[i]);",
		  "        else *it=v[i];",
		  "    }",
		  "    return dp.size();",
		  "}"
		],
		"description": "Lowest Increasing subsequence"
	  },
	  "LCS(sequence)": {
		"prefix": "lcs2",
		"scope": "cpp",
		"body": [
		  "string lcs(string &s1,string &s2){",
		  "    vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1));",
		  "    vector<vector<pair<int,int>>>parent(s1.length()+1,vector<pair<int,int>>(s2.length()+1));",
		  "    for(int i=1;i<=s1.length();i++){",
		  "        for(int j=1;j<=s2.length();j++){",
		  "            if(s1[i-1]==s2[j-1]){",
		  "                dp[i][j]=dp[i-1][j-1]+1;",
		  "                parent[i][j]={-1,-1};",
		  "            }",
		  "            else if(dp[i-1][j]>dp[i][j-1]){",
		  "                dp[i][j]=dp[i-1][j];",
		  "                parent[i][j]={-1,0};",
		  "            }",
		  "            else{",
		  "                dp[i][j]=dp[i][j-1];",
		  "                parent[i][j]={0,-1};",
		  "            }",
		  "        }",
		  "    }",
		  "    pair<int,int>p={s1.length(),s2.length()};",
		  "    string s=\"\";",
		  "    while((p.ff!=0&&p.ss!=0)){",
		  "        if(parent[p.ff][p.ss].ff==-1 && parent[p.ff][p.ss].ss==-1){",
		  "            s.push_back(s1[p.ff-1]);",
		  "        }",
		  "        p={p.ff+parent[p.ff][p.ss].ff,p.ss+parent[p.ff][p.ss].ss};",
		  "    }",
		  "    reverse(begin(s),end(s));",
		  "    debug(dp)",
		  "    return s;",
		  "    ",
		  "}"
		],
		"description": "LCS(sequence)"
	  },
	  "Max Sub Array Sum": {
		"prefix": "maxsubarraysum",
		"body": [
		  "//Time Complexity:O(N) Auxilari Space:O(1)",
		  "pair<int,int> maxsubarraysum(vector<int>&arr){",
		  "    int maxsum=0,currentsum=0,startindex=0,tmp=0;",
		  "    for(int i=0;i<arr.size();i++){",
		  "        currentsum+=arr[i];",
		  "        if(currentsum>maxsum){",
		  "            startindex=tmp;",
		  "            maxsum=currentsum;",
		  "        }",
		  "        if(currentsum<0){",
		  "            currentsum=0;tmp=i+1;",
		  "        }",
		  "    }",
		  "    return {maxsum,startindex};",
		  "}"
		],
		"description": "Max Sub Array Sum"
	  }
}