SELECT T.Name, T.Surname, T.BirthDate, SC.CampName
FROM TEENAGER T, SUMMER-CAMP SC, SUBSCRIPTION-TO-ACTIVITY-IN-SUMMER-CAMP STAISC
WHERE T.SSN = STAISC.SSN AND STAISC.CampCode = SC.CampCode
	AND SSN IN (SELECT T.SSN #born before 2005 and at least 5 camps
					FROM TEENAGER T, SUBSCRIPTION-TO-ACTIVITY-IN-SUMMER-CAMP STAISC
					WHERE T.BirthDate < TO_DATE('01/01/2005', 'DD/MM/YYYY')
							AND T.SSN = STAISC.SSN
					GROUP BY T.SSN
					HAVING COUNT(DISTINCT STAISC.CampCode) > 4)
GROUP BY T.SSN, SC.CampName
HAVING (STAISC.CampCode, COUNT(DISTINCT ActivityCode)) IN (SELECT CampCode, COUNT(DISTINCT ActivityCode) #number of activities in camps
															FROM SUBSCRIPTION-TO-ACTIVITY-IN-SUMMER-CAMP
															GROUP BY CampCode)
