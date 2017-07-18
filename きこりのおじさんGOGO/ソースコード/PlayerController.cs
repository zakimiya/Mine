using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class PlayerController : MonoBehaviour
{
    public float speed = 10;
    public static int score;
    public UnityEngine.UI.Text scoreLabel, axLabel;
    private int no_score,no_damage;

    private int ax;
    private int dead, dead_count;
    

    void Start()
    {
        transform.eulerAngles = new Vector3(0, 0, 0);
        score = 0;
        no_score = 0;
        no_damage = 0;
        ax = 10;
        dead = 0;
        dead_count = 0;
    }

    void FixedUpdate()
    {
        float x = Input.GetAxis("Horizontal");
        float z = Input.GetAxis("Vertical");

        Rigidbody rigidbody = GetComponent<Rigidbody>();

        // xとyにspeedを掛ける
        rigidbody.AddForce(x * speed, 0, z * speed);

        Vector3 pos = transform.position;
        Vector3 rot = transform.localEulerAngles;

        if (pos.y > 0.0f || pos.y < 0.0f) pos.y = 0.0f;
        if (rot.x > 0.0f || rot.x < 0.0f) rot.x = 0.0f;
        if (rot.z > 0.0f || rot.z < 0.0f) rot.z = 0.0f;

        rot.y += 25;

        no_score--;
        if (no_score < 0) no_score = -1;

        no_damage--;
        if (no_damage < 0) no_damage = -1;


        if (ax == 0) SceneManager.LoadScene("axbreak");

        if (dead == 1) dead_count++;
        if (dead_count > 10) SceneManager.LoadScene("dead");

        transform.position = pos;
        transform.localEulerAngles = rot;
        scoreLabel.text = score.ToString();
        axLabel.text = ax.ToString();
    }

    void OnTriggerEnter(Collider hit)
    {
        if (hit.CompareTag("Tree"))
        {
            if (no_score <= 0)
            {
                score++;
                no_score = 15;
            }

        }
        if (hit.CompareTag("Ax"))
        {
            ax += 5;
        }
    }

    void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "Rock")
        {
            if (no_damage <= 0)
            {
                ax--;
                no_damage = 15;
            }

        }
        if (collision.gameObject.tag == "Bear")
        {
            dead = 1;
        }
    }
}