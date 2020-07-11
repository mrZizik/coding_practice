val string = "ran sim ka"
val symbols = "%20"

//Напишите метод, заменяющий все пробелы в строке символами '%20'. Можете
//считать, что длина строки позволяет сохранить дополнительные символы,
//а фактическая длина строки известна заранее. (Примечание: при реализации
//        метода на Java для выполнения операции «на месте» используйте символьный
//массив.)

fun replaceSpaces(charArray: CharArray, length: Int): CharArray {
    var spaceCount = 0

    charArray.forEach {
        if (it == ' ') {
            spaceCount++
        }
    }
    var index = length + spaceCount * 2 + 1
    charArray[index] = '\\'
    for (i in length downTo 0) {
        if (charArray[i] != ' ') {
            charArray[index - 1] = charArray[i]
            index--
        } else {
            charArray[index - 1] = symbols[2]
            charArray[index - 2] = symbols[1]
            charArray[index - 3] = symbols[0]
            index-=3
        }
    }
    return charArray
}

var charArray = CharArray(string.length + 3 * 2 + 1)

for (i in string.indices) {
    charArray[i] = string[i]
}

print(replaceSpaces(charArray, string.length))
