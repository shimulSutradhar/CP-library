vector<int> supermask[1 << n];
for (int supMask=0; supMask < (1 << n); ++supMask){
  for (int subMask = supMask; subMask; subMask = (subMask - 1) & supMask){
    if(validSubMask[subMask]){
      supermask[supMask].emplace_back(subMask);
    }
  }
}
