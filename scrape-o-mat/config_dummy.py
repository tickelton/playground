configuration = {
    "user_agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36",
    "login" : {
        "url" : "https://example.com/Admin/Login",
        "post_data" : {
            "Email" : "foobar@example.com",
            "Password" : "foobar",
            "mode" : "Light"
        }
    },
    "fetch" : {
        "url" : "https://example.com/Data/Select",
        "post_data" : {
            "Min" : 500,
            "Max" : 512,
            "type" : "basic"
        }
    },
    "logout" : {
        "url" : "https://example.com/Admin/Logout",
    },
    "target_frame" : 3,
    "expected_cols" : [
        'Value (ms)',
        'Date',
        'Foobar',
    ],
    "db_path" : "exampledb.sqlite",
    "table_name" : "MyData"
}
