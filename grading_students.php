<?php

/*
 * Complete the gradingStudents function below.
 */
function gradingStudents($grades) {
    /*
     * Write your code here.
     */
    for ($i = 0; $i< sizeof($grades); $i+=1)
    {   
        if ($grades[$i] >= 38 )  #no rounding off for grades less than 38
        {
            if (($grades[$i] % 5 == 3) or ($grades[$i] %5 == 4 ))
             $grades[$i]+= 5- ($grades[$i] % 5); 
        }
    }
    return $grades;

}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$__fp = fopen("php://stdin", "r");

fscanf($__fp, "%d\n", $n);

$grades = array();

for ($grades_itr = 0; $grades_itr < $n; $grades_itr++) {
    fscanf($__fp, "%d\n", $grades_item);
    $grades[] = $grades_item;
}

$result = gradingStudents($grades);

fwrite($fptr, implode("\n", $result) . "\n");

fclose($__fp);
fclose($fptr);
