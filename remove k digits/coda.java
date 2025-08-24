class Solution {
    public String removeKdigits(String num, int k) {
        Deque<Character> stk = new ArrayDeque<>();

        for(char ch : num.toCharArray()){
            while(!stk.isEmpty() && k > 0 && stk.peekLast() > ch){
                stk.pollLast();
                k--;
            }
            stk.offerLast(ch);
        }

        while(k > 0 && !stk.isEmpty()){
            stk.pollLast();
            k--;
        }

        while(!stk.isEmpty() && stk.peekFirst() == '0') stk.pollFirst();

        StringBuilder result = new StringBuilder();
        while(!stk.isEmpty()){
            result.append(stk.peekFirst());
            stk.pollFirst();
        }

        return result.isEmpty() ? "0" : result.substring(0);
    }
}