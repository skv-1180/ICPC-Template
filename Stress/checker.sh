g++ test.cpp -o test
g++ good.cpp -o good
g++ randomTestGenerator.cpp -o randomTestGenerator

for((i = 1; ; ++i)); do
    ./randomTestGenerator $i > random_Input.t
    ./test <random_Input.t > test_Output.t
    ./good <random_Input.t > good_output.t
    diff -w test_Output.t good_output.t || break
    echo "Passed test: "  $i
done

echo -e "\nWA on the following test:"
cat random_Input.t
echo "Your answer is:"
cat test_Output.t
echo "Correct answer is:"
cat good_output.t