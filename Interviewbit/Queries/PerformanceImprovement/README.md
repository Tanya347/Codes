![image](https://user-images.githubusercontent.com/80675137/180044877-bfa0a3f5-d92b-487b-9293-059d31761e43.png)

## QUERY

`
SELECT Tests.TestId
FROM Tests
JOIN Tests as t 
ON t.TestId = Tests.TestId - 1
WHERE Tests.Marks>t.Marks
`
