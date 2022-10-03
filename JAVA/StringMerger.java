public class StringMerger {
    public static boolean isMerge(String s, String part1, String part2){
        if (s.length() != part1.length() + part2.length()) return false;
        if (s.length() == 0) return true;
        if (part1.length() > 0 && s.charAt(0) == part1.charAt(0) && isMerge(s.substring(1), part1.substring(1), part2)) return true;
        if (part2.length() > 0 && s.charAt(0) == part2.charAt(0) && isMerge(s.substring(1), part1, part2.substring(1))) return true;
        return false;
    }
}
