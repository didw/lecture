library(httr)
require(httpuv)
require(jsonlite)

# 1. Find OAuth settings for github: http://developer.github.com/v3/oauth/
oauth_endpoints("github")

# 2. Register an application at https://github.com/settings/applications
# Insert your values below - if secret is omitted, it will look it up in the
# GITHUB_CONSUMER_SECRET environmental variable.  Use http://localhost:1410
# as the callback url
myapp <- oauth_app("didw", "6c9173f810d6f87a3570", secret = "d804fa5a37d4c360d422a8db53156fff3bde77bb")

# 3. Get OAuth credentials
github_token <- oauth2.0_token(oauth_endpoints("github"), myapp)

# 4. Use API
req <- GET("https://api.github.com/users/jtleek/repos", config(token = github_token))
stop_for_status(req)
output <- content(req)
output2 <- list(output[[8]]$name, output[[8]]$created_at)
print(output2)