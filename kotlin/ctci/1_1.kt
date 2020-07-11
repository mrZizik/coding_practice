// Реализуйте алгоритм, определяющий, все ли символы в строке встречаются
// только один раз. А если при этом запрещено использование дополнительных
// структур данных?

val string = "ran sim ka"

fun areLetterRepeating(input: String): Boolean {
    for (i in input.indices) {
        for (j in input.indices) {
            if (i != j && input[i] == input[j]) {
                return true
            }
        }
    }

    return false
}

fun areLetterRepeating2(input: String): Boolean {
    val lettersMap = mutableMapOf<Char, Int>()
    var result = false

    for (char in input) {
        lettersMap[char] = lettersMap.getOrDefault(char, 0) + 1
    }

    lettersMap.forEach { (_, i) ->
        if (i > 1) {
            result = true
        }
    }

    return result
}

print(areLetterRepeating(string))
print(areLetterRepeating2(string))
