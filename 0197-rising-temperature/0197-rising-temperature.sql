-- Create a CTE to calculate the previous day's temperature and date
# WITH q1 AS (
#   SELECT 
#       *,
#       LAG(temperature) OVER (ORDER BY recordDate) AS previous_day_temperature,
#       LAG(recordDate) OVER (ORDER BY recordDate) AS previous_Date
#   FROM Weather
# )

# -- Select the IDs where the temperature is higher than the previous day
# -- and the previous day exists (difference is exactly 1 day)
# SELECT id
# FROM q1
# WHERE temperature > previous_day_temperature
# AND DATEDIFF(recordDate, previous_Date) = 1;


select w1.id from weather W1, weather w2 where datediff(w1.recordDate,w2.recordDate) = 1 and w1.temperature > w2.temperature;