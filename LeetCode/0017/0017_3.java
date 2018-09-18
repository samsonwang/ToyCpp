
// 使用了BFS，breadth first search

public List<String> letterCombinations(String digits) {
    LinkedList<String> ans = new LinkedList<String>();
    if(digits.isEmpty()) {
        return ans;
    }

    String[] mapping = new String[] {"0", "1", "abc", "def",
                                     "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    ans.add("");
    for(int i=0; i<digits.length(); i++) {
        int x = Character.getNumericValue(digits.charAt(i));

        while(ans.peek().length() == i) {
            String t = ans.remove(); // remove是从头部删去一个元素
            for(char s : mapping[x].toCharArray()) {
                ans.add(t+s); // add是向尾部添加一个元素
            }
        }
    }
    return ans;
}

public List<String> letterCombinations(String digits) {
    LinkedList<String> ans = new LinkedList<String>();
    if(digits.isEmpty()) {
        return ans;
    }
    String[] mapping = new String[] {"0", "1", "abc", "def",
                                     "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    ans.add("");
    while(ans.peek().length() != digits.length()){
        String remove = ans.remove();
        String map = mapping[digits.charAt(remove.length())-'0'];
        for(char c: map.toCharArray()){
            ans.addLast(remove+c);
        }
    }
    return ans;
}
