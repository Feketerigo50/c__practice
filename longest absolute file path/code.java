Map<Integer, Integer> depthLen = new HashMap<>();
        depthLen.put(0, 0);
        int maxLen = 0;

        String[] lines = input.split("\n");
        for (String line : lines) {
            int depth = 0;
            while (line.startsWith("\t", depth)) depth++;

            String name = line.substring(depth);
            if (name.contains(".")) {
                // 檔案
                maxLen = Math.max(maxLen, depthLen.get(depth) + name.length());
            } else {
                // 資料夾
                depthLen.put(depth + 1, depthLen.get(depth) + name.length() + 1);
            }
        }
        return maxLen;