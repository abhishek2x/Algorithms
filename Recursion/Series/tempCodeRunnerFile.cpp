  if(open != 0){
      string ans1 = ans+ "(";
      getParathesised(ans1, open-1, close);
    }
    if(close < open) {
      string ans1 = ans + ")";
      getParathesised(ans1, open, close-1);
  